/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package info.stepanoff.trsis.samples.db.dao;

/**
 *
 * @author Demid
 */
import info.stepanoff.trsis.samples.db.model.Groups;
import java.util.List;
import org.springframework.data.repository.CrudRepository;

public interface GroupsRepository extends CrudRepository<Groups, Integer> {
}