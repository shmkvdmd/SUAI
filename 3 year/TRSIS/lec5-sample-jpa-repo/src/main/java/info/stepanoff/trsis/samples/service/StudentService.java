package info.stepanoff.trsis.samples.service;

import info.stepanoff.trsis.samples.db.model.Student;

public interface StudentService {

    Iterable<Student> listAll();

    void delete(Integer id);
    
    Student add(String fullName, int assignmentVariant, int labCount, int rating);
    
    Student getById(Integer id);

}
