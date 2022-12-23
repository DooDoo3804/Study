package com.example.testproject.data.repository;

import com.example.testproject.data.entity.ProductEntity;
import org.springframework.data.jpa.repository.JpaRepository;
public interface ProductRepository extends JpaRepository<ProductEntity, String>{

}
