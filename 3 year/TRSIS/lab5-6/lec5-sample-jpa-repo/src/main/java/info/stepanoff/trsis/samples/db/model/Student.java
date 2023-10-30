package info.stepanoff.trsis.samples.db.model;

import java.io.Serializable;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "Student")
public class Student implements Serializable {

    private static final long serialVersionUID = 1L;

    public Student() {
    }

    public Student(Integer id, String fullName, int assignmentVariant, int labCount, int rating, String groupNumber) {
        this.id = id;
        this.fullName = fullName;
        this.assignmentVariant = assignmentVariant;
        this.labCount = labCount;
        this.rating = rating;
        this.groupNumber = groupNumber; 
    }

    @Id
    @Column(name = "student_id")
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getId() {
        return id;
    }

    @Column(name = "student_full_name")
    private String fullName;

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public String getFullName() {
        return fullName;
    }

    @Column(name = "student_assignment_variant")
    private Integer assignmentVariant;

    public void setAssignmentVariant(Integer assignmentVariant) {
        this.assignmentVariant = assignmentVariant;
    }

    public Integer getAssignmentVariant() {
        return assignmentVariant;
    }

    @Column(name = "student_lab_count")
    private Integer labCount;

    public void setLabCount(Integer labCount) {
        this.labCount = labCount;
    }

    public Integer getLabCount() {
        return labCount;
    }

    @Column(name = "student_rating")
    private Integer rating;

    public void setRating(Integer rating) {
        this.rating = rating;
    }

    public Integer getRating() {
        return rating;
    }
    @Column(name = "student_group")
    private String groupNumber;

    public void setGroupNumber(String groupNumber) {
        this.groupNumber = groupNumber;
    }

    public String getGroupNumber() {
        return groupNumber;
    }
}
