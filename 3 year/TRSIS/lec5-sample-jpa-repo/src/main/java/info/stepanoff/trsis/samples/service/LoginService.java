/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package info.stepanoff.trsis.samples.service;

/**
 *
 * @author Demid
 */
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UsernameNotFoundException;

public interface LoginService {

    public UserDetails loadUserByUsername(String string) throws UsernameNotFoundException;



}