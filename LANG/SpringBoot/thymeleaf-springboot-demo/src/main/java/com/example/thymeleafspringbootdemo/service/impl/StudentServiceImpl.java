package com.example.thymeleafspringbootdemo.service.impl;

import com.example.thymeleafspringbootdemo.entity.Student;
import com.example.thymeleafspringbootdemo.repository.StudentRepository;
import com.example.thymeleafspringbootdemo.service.StudentService;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class StudentServiceImpl implements StudentService {

    private StudentRepository studentRepository;

    public StudentServiceImpl(StudentRepository studentRepository) {
        super();
        this.studentRepository = studentRepository;
    }

    @Override
    public List<Student> getAllStudents() {
        return studentRepository.findAll();
    }

    @Override
    public Student saveStudent(Student student) {
        return studentRepository.save(student);
    }
}
