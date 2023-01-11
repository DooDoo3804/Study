package com.example.springbootdemo.controller;

import com.example.springbootdemo.model.Employee;
import com.example.springbootdemo.repository.EmployeeRepository;
import com.example.springbootdemo.service.EmployeeService;
import jakarta.websocket.server.PathParam;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping(path = "/api/employees")
public class EmployeeController {
    private EmployeeService employeeService;
    private final EmployeeRepository employeeRepository;

    public EmployeeController(EmployeeService employeeService,
                              EmployeeRepository employeeRepository) {
        super();
        this.employeeService = employeeService;
        this.employeeRepository = employeeRepository;
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

    //build get employee by id REST API
    @GetMapping(value = "{id}")
    public ResponseEntity<Employee> getEmployeeById(@PathVariable("id") long employeeId) {
        return new ResponseEntity<Employee>(employeeService.getEmployeeById(employeeId), HttpStatus.OK);
    }

    //build update employee REST API
    @PutMapping(value = "{id}")
    public ResponseEntity<Employee> updateEmployee(@PathVariable("id") long id,
                                                   @RequestBody Employee employee) {
        return new ResponseEntity<Employee>(employeeService.updateEmployee(employee, id), HttpStatus.OK);
    }

    //build delete employee REST API
    @DeleteMapping(value = "{id}")
    public ResponseEntity<String> deleteEmployee(@PathVariable("id") long id) {
        employeeService.deleteEmployee(id);
        return new ResponseEntity<String>("Employee deleted successfully!!", HttpStatus.OK);
    }
}
