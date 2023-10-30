/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package info.stepanoff.trsis.samples.service;

/**
 *
 * @author Demid
 */
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import info.stepanoff.trsis.samples.db.dao.GroupsRepository;
import info.stepanoff.trsis.samples.db.model.Groups;

@Service
public class GroupsServiceImpl implements GroupsService {

    private final GroupsRepository groupsRepository;

    @Autowired
    public GroupsServiceImpl(GroupsRepository groupsRepository) {
        this.groupsRepository = groupsRepository;
    }

    @Override
    public Iterable<Groups> listAll() {
        return groupsRepository.findAll();
    }

    @Override
    public Groups getById(Integer id) {
        return groupsRepository.findById(id).orElse(null);
    }

    @Override
    public Groups add(String number) {
        return groupsRepository.save(new Groups(number));
    }

    @Override
    public void delete(Integer id) {
        groupsRepository.deleteById(id);
    }
}
