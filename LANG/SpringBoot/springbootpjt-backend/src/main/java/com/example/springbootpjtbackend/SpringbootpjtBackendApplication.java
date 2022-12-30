package com.example.springbootpjtbackend;

import com.example.springbootpjtbackend.entity.Employee;
import com.example.springbootpjtbackend.repository.EmployeeRepository;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class SpringbootpjtBackendApplication implements CommandLineRunner {
    private final EmployeeRepository employeeRepository;

    public SpringbootpjtBackendApplication(EmployeeRepository employeeRepository) {
        this.employeeRepository = employeeRepository;
    }

    public static void main(String[] args) {
        SpringApplication.run(SpringbootpjtBackendApplication.class, args);
    }

    @Override
    public void run(String... args) throws Exception {
        Employee employee1 = Employee.builder()
                .firstName("DooDoo")
                .lastName("Doll")
                .email("Doo@gmail.com")
                .build();

        Employee employee2 = Employee.builder()
                .firstName("A")
                .lastName("Author")
                .email("A@gmail.com")
                .build();

        Employee employee3 = Employee.builder()
                .firstName("Michel")
                .lastName("M")
                .email("M@gmail.com")
                .build();
        employeeRepository.save(employee1);
        employeeRepository.save(employee2);
        employeeRepository.save(employee3);
    }
}
