package info.stepanoff.trsis.samples.service;

import info.stepanoff.trsis.samples.db.model.Student;

public interface StudentService {

    Iterable<Student> listAll();

    void delete(Integer id);
    
    Student add(String fullName, int assignmentVariant, int labCount, int rating, String groupNumber);
    
    Student getById(Integer id);
    
    Iterable<Student> findByFullName(String fullName);
    
    Iterable<Student> findByGroupNumber(String groupNumber);

}
