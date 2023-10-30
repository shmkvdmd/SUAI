package info.stepanoff.trsis.samples.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import info.stepanoff.trsis.samples.db.model.Student;
import lombok.extern.slf4j.Slf4j;
import info.stepanoff.trsis.samples.db.dao.StudentRepository;

@Slf4j
@Service
public class StudentServiceImpl implements StudentService {
    @Autowired
    private StudentRepository studentRepository;

    @Override
    public Iterable<Student> listAll() {
        return studentRepository.findAll();
    }

    @Override
    public void delete(Integer id) {
        try {
            studentRepository.deleteById(id);
        } catch (org.springframework.dao.EmptyResultDataAccessException e) {
        }
    }

    @Override
    public Student add(String fullName, int assignmentVariant, int labCount, int rating, String groupNumber) {
        return studentRepository.save(new Student(null, fullName, assignmentVariant, labCount, rating, groupNumber));
    }

    @Override
    public Student getById(Integer id) {
        return studentRepository.findById(id).orElse(null);
    }
    
    @Override
    public Iterable<Student> findByFullName(String fullName) {
        return studentRepository.findByFullName(fullName);
    }
    
    @Override
    public Iterable<Student> findByGroupNumber(String groupNumber) {
    return studentRepository.findByGroupNumber(groupNumber);
    }
    
}
