package com.example.springbootpjtbackend.controller;


import com.example.springbootpjtbackend.entity.Employee;
import com.example.springbootpjtbackend.repository.EmployeeRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class EmployeeController {

    @Autowired
    private EmployeeRepository employeeRepository;

    @GetMapping(value = "/employees")
    private List<Employee> fetchEmployee() {
        return employeeRepository.findAll();
    }


}
