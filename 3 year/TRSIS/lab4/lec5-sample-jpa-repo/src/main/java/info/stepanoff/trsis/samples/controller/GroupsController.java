package info.stepanoff.trsis.samples.controller;

import info.stepanoff.trsis.samples.db.model.Groups;
import info.stepanoff.trsis.samples.service.GroupsService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

@Slf4j
@Controller
public class GroupsController {

    @Autowired
    GroupsService groupsService;

    @RequestMapping(value = "/groups/{id}", method = RequestMethod.GET)
    public ModelAndView groups(@PathVariable("id") Integer id, Model model) {
        if (!model.containsAttribute("group")) {
            Groups newGroup = new Groups();
            newGroup.setId(id);
            model.addAttribute("group", newGroup);
        }

        ModelAndView mav = new ModelAndView();
        mav.setViewName("groups");
        Iterable<Groups> groups = (Iterable<Groups>) groupsService.getById(id);
        if (groups.iterator() != null) {
            log.info("for school_id " + id + " found " + (groups.iterator().hasNext() ? "non-empty iterator" : "empty iterator"));
        } else {
            log.error("groups.iterator() is null! for school=" + id);
        }

        mav.addObject("groups", groups);
        mav.addObject("school_id", id);
        log.info("MaV contains school_id=" + id);
        return mav;
    }

    @RequestMapping(value = "/groups/save", method = RequestMethod.GET)
    public String saveGroup(Model model) {
        model.addAttribute("group", new Groups());
        return "groups";
    }

    @RequestMapping(value = "/groups", method = RequestMethod.POST)
    public ModelAndView saveGroup(@ModelAttribute Groups group, BindingResult errors, Model model) {
        log.info("Saving group " + group);
        groupsService.add(group.getNumber());
        return groups(group.getId(), model);
    }
}
