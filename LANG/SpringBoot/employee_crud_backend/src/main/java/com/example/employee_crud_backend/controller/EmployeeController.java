package com.example.employee_crud_backend.controller;

import com.example.employee_crud_backend.exception.ResourceNotFoundException;
import com.example.employee_crud_backend.model.Employee;
import com.example.employee_crud_backend.repository.EmployeeRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
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

   @GetMapping(value = "/employees/{id}")
    public ResponseEntity<Employee> getEmployeeById(@PathVariable Long id) {
        Employee employee = employeeRepository.findById(id).orElseThrow( () -> new ResourceNotFoundException("Employee not exist with id :" + id));
        return ResponseEntity.ok(employee);
   }

   @PutMapping(value = "/employees/{id}")
    public ResponseEntity<Employee> updateEmployee(@PathVariable Long id, @RequestBody Employee employeeDetails) {
       Employee employee = employeeRepository.findById(id).orElseThrow( () -> new ResourceNotFoundException("Employee not exist with id :" + id));

       employee.setFirstName(employeeDetails.getFirstName());
       employee.setLastName(employeeDetails.getLastName());
       employee.setEmail(employeeDetails.getEmail());

       Employee updatedEmployee = employeeRepository.save(employee);
       return ResponseEntity.ok(updatedEmployee);
   }
}
