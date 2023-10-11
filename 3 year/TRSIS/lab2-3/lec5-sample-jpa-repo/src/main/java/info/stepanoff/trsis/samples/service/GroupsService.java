/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package info.stepanoff.trsis.samples.service;
import info.stepanoff.trsis.samples.db.model.Groups;

/**
 *
 * @author Demid
 */
public interface GroupsService {

    Iterable<Groups> listAll();

    Groups getById(Integer id);
    
    Groups add(String number);
    
    void delete(Integer id);
}