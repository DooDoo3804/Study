package com.example.thymeleafspringbootdemo;

import com.example.thymeleafspringbootdemo.entity.Student;
import com.example.thymeleafspringbootdemo.repository.StudentRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class ThymeleafSpringbootDemoApplication implements CommandLineRunner {

    public static void main(String[] args) {
        SpringApplication.run(ThymeleafSpringbootDemoApplication.class, args);
    }

    @Autowired
    private StudentRepository studentRepository;

    @Override
    public void run(String... args) throws Exception {

    }
}
