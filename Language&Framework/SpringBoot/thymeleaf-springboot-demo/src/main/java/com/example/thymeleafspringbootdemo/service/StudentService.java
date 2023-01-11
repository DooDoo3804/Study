package com.example.thymeleafspringbootdemo.service;

import com.example.thymeleafspringbootdemo.entity.Student;

import java.util.List;


public interface StudentService {
    List<Student> getAllStudents();
    Student saveStudent(Student student);
    Student getStudentById(Long id);
    Student editStudent(Student student);
    void deleteStudentById(Long id);
}
