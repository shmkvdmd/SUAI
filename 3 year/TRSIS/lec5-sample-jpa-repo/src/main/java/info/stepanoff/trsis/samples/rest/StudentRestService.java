package info.stepanoff.trsis.samples.rest;

import info.stepanoff.trsis.samples.db.model.Student;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import info.stepanoff.trsis.samples.service.StudentService;
import lombok.extern.slf4j.Slf4j;

@Slf4j
@RestController
@RequestMapping("/public/rest/students")
public class StudentRestService {

    @Autowired
    private StudentService studentService;

    @RequestMapping(value = "", method = RequestMethod.GET)
    public ResponseEntity<Object> browse() {
        return ResponseEntity.ok(studentService.listAll());
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public void delete(@PathVariable("id") Integer id) {
        studentService.delete(id);
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    public ResponseEntity<Object> getOne(@PathVariable("id") Integer id) {
        Student studentById = studentService.getById(id);
        if (studentById == null) {
            return ResponseEntity.notFound().build();
        } else {
            return ResponseEntity.ok(studentById);
        }
    }

    @RequestMapping(value = "/{fullName}/{assignmentVariant}/{labCount}/{rating}", method = RequestMethod.POST)
    public ResponseEntity<Object> add(@PathVariable("fullName") String fullName, @PathVariable("assignmentVariant") int assignmentVariant, @PathVariable("labCount") int labCount, @PathVariable("rating") int rating) {
        return ResponseEntity.ok(studentService.add(fullName, assignmentVariant, labCount, rating));
    }
}
