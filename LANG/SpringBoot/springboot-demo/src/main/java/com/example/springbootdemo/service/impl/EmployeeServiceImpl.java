package com.example.springbootdemo.service.impl;

import com.example.springbootdemo.exception.ResourceNotFoundException;
import com.example.springbootdemo.model.Employee;
import com.example.springbootdemo.repository.EmployeeRepository;
import com.example.springbootdemo.service.EmployeeService;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class EmployeeServiceImpl implements EmployeeService {

    private EmployeeRepository employeeRepository;

    public EmployeeServiceImpl(EmployeeRepository employeeRepository) {
        super();
        this.employeeRepository = employeeRepository;
    }

    @Override
    public Employee saveEmployee(Employee employee) {
        return employeeRepository.save(employee);
    }

    @Override
    public List<Employee> getAllEmployees() {
        return employeeRepository.findAll();
    }

    @Override
    public Employee getEmployeeById(long id) {
//        Optional<Employee> employee = employeeRepository.findById(id);
//        if (employee.isPresent())
//            return employee.get();
//        else
//            throw new ResourceNotFoundException("Employee", "Id", id);
//        위와 아래는 같은 코드
        return employeeRepository.findById(id).orElseThrow(() ->
                new ResourceNotFoundException("Employee", "id", id));
    }

    @Override
    public Employee updateEmployee(Employee employee, long id) {
        Employee existingEmployee = employeeRepository.findById(id).orElseThrow(() ->
                new ResourceNotFoundException("Employee", "id", id));
        existingEmployee.setFirstName(employee.getFirstName());
        existingEmployee.setLastName(employee.getLastName());
        existingEmployee.setEmail(employee.getEmail());
        employeeRepository.save(existingEmployee);
        return existingEmployee;
    }

    @Override
    public void deleteEmployee(long id) {
        employeeRepository.findById(id).orElseThrow(() ->
                new ResourceNotFoundException("employee", "id", id));
        employeeRepository.deleteById(id);
    }


}
