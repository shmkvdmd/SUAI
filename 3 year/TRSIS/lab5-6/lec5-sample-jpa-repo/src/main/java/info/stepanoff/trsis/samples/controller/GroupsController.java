package info.stepanoff.trsis.samples.controller;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;
import info.stepanoff.trsis.samples.db.model.Groups;
import info.stepanoff.trsis.samples.db.model.Student;
import info.stepanoff.trsis.samples.service.GroupsService;
import info.stepanoff.trsis.samples.service.StudentService;

@Slf4j
@Controller
public class GroupsController {

    @Autowired
    private GroupsService groupsService;

    @Autowired
    private StudentService studentService;

    @RequestMapping(value = "/groups", method = RequestMethod.GET)
    public ModelAndView listGroups(Model model) {
        ModelAndView mav = new ModelAndView();
        mav.setViewName("groups");

        Iterable<Groups> groups = groupsService.listAll();
        mav.addObject("groups", groups);

        model.addAttribute("group", new Groups());

        return mav;
    }

    @RequestMapping(value = "/groups/save", method = RequestMethod.GET)
    public String saveGroup(Model model) {
        model.addAttribute("group", new Groups());
        return "groups";
    }

    @RequestMapping(value = "/groups/save", method = RequestMethod.POST)
    public ModelAndView saveGroup(@ModelAttribute("group") Groups group, BindingResult errors, Model model) {
        log.info("Saving group " + group);
        groupsService.add(group.getNumber());
        return new ModelAndView("redirect:/groups");
    }
    
    @RequestMapping(value = "/groups/delete/{groupId}", method = RequestMethod.GET)
    public ModelAndView deleteGroup(@PathVariable("groupId") Integer groupId) {
        groupsService.delete(groupId);
        return new ModelAndView("redirect:/groups");
    }

}
