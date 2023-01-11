package com.example.springbootpjtbackend.repository;

import com.example.springbootpjtbackend.entity.Employee;
import org.springframework.data.jpa.repository.JpaRepository;

public interface EmployeeRepository extends JpaRepository<Employee, Long> {
}
