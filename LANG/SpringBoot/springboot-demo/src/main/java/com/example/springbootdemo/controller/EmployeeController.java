package com.example.springbootdemo.controller;

import com.example.springbootdemo.model.Employee;
import com.example.springbootdemo.service.EmployeeService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping(path = "/api/employees")
public class EmployeeController {
    private EmployeeService employeeService;

    public EmployeeController(EmployeeService employeeService) {
        super();
        this.employeeService = employeeService;
    }

    //build create employee REST API
    @PostMapping(value = "")
    public ResponseEntity<Employee> saveEmployee(@RequestBody Employee employee) {
        return new ResponseEntity<Employee>(employeeService.saveEmployee(employee), HttpStatus.CREATED);

    }

    //build get all employees REST API
    @GetMapping(value = "")
    public List<Employee> getAllEmployees() {
        return employeeService.getAllEmployees();
    }
}
