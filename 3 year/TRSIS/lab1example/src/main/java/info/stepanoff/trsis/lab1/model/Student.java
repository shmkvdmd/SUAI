/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package info.stepanoff.trsis.lab1.model;

/**
 *
 * @author Demid
 */
public class Student {
    private static int nextId = 0;
    private int id;
    private String fullName;
    private int assignmentVariant;
    private int labCount;
    private int rating;

    public Student(String fullName, int assignmentVariant, int labCount, int rating) {
        this.id = nextId++;
        this.fullName = fullName;
        this.assignmentVariant = assignmentVariant;
        this.labCount = labCount;
        this.rating = rating;
    }

    public int getId() {
        return id;
    }
    
    public String getFullName() {
        return fullName;
    }

    public int getAssignmentVariant() {
        return assignmentVariant;
    }

    public int getLabCount() {
        return labCount;
    }

    public int getRating() {
        return rating;
    }
}