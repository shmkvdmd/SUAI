package info.stepanoff.trsis.samples.db.dao;

import info.stepanoff.trsis.samples.db.model.Student;
import org.springframework.data.repository.CrudRepository;
import java.util.List;

/**
 *
 * @author Pavel
 */
public interface StudentRepository extends CrudRepository<Student, Integer> {

    List<Student> findByFullName(String fullName);
    List<Student> findByGroupNumber(String groupNumber);

}
