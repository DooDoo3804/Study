package com.example.employee_crud_backend.controller;

import com.example.employee_crud_backend.model.Employee;
import com.example.employee_crud_backend.repository.EmployeeRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping(value = "/api/v1")
@CrossOrigin("http://localhost:3000/")
public class EmployeeController {

    @Autowired
    private EmployeeRepository employeeRepository;

    @GetMapping(value = "/employees")
    public List<Employee> getAllEmployees() {
        return employeeRepository.findAll();
    }

    @PostMapping(value = "/employees")
   public Employee createEmployee(@RequestBody Employee employee) {
        return employeeRepository.save(employee);
   }
}
