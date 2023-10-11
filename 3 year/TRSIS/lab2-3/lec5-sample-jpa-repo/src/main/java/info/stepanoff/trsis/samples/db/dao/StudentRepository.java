package info.stepanoff.trsis.samples.db.dao;

import info.stepanoff.trsis.samples.db.model.Student;
import org.springframework.data.repository.CrudRepository;

/**
 *
 * @author Pavel
 */
public interface StudentRepository extends CrudRepository<Student, Integer> {

    // List<School> findByNumber(Integer number);
}
