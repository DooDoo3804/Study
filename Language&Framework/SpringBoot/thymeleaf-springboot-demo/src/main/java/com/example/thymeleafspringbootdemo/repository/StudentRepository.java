package com.example.thymeleafspringbootdemo.repository;

import com.example.thymeleafspringbootdemo.entity.Student;
import org.springframework.data.jpa.repository.JpaRepository;

// @Repository
// SimpleJpaRepository
public interface StudentRepository extends JpaRepository<Student, Long> {

}
