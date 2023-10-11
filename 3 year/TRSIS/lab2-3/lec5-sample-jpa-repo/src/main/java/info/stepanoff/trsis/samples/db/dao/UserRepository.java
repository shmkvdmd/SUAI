/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package info.stepanoff.trsis.samples.db.dao;

/**
 *
 * @author Demid
 */
import info.stepanoff.trsis.samples.db.model.User;
import org.springframework.data.repository.CrudRepository;

public interface UserRepository
        extends CrudRepository<User, Integer> {

    User findByLogin(String login);

}