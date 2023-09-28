/*
 * this code is available under GNU GPL v3
 * https://www.gnu.org/licenses/gpl-3.0.en.html
 */
package info.stepanoff.trsis.lab1.model;
import java.util.ArrayList;
import java.util.List;
/**
 *
 * @author Pavel.Stepanov
 */
public  class DataModel {
    private static final List<Student> students = new ArrayList<>();
    private static int nextId = 0;
    
    static {
        students.add(new Student("Петров Петр Петрович", 1, 5, 90));
        students.add(new Student("Петров Петр Петрович", 2, 0, 0));
        students.add(new Student("Петров Петр Петрович", 3, 4, 80));
        students.add(new Student("Петров Петр Петрович", 4, 5, 90));
        students.add(new Student("Петров Петр Петрович", 5, 4, 80));
        students.add(new Student("Петров Петр Петрович", 6, 2, 50));
        students.add(new Student("Петров Петр Петрович", 7, 3, 70));
        students.add(new Student("Петров Петр Петрович", 8, 5, 90));
    }
    public static List<Student> getAllStudents() {
        return students;
    }
    public static void addStudent(Student student) {
        students.add(student);
    }
    
    public static void deleteStudentById(int studentId) {
        students.removeIf(student -> student.getId() == studentId);
    }
    public static List<Student> searchStudents(String searchQuery) {
        List<Student> searchResults = new ArrayList<>();
        for (Student student : students) {
            if (student.getFullName().contains(searchQuery)) {
                searchResults.add(student);
            }
        }
        return searchResults;
    }
}
