package com.example.springbootdemo.service;

import com.example.springbootdemo.model.Employee;

import java.util.List;

public interface EmployeeService {
    Employee saveEmployee(Employee employee);
    List<Employee> getAllEmployees();

}
