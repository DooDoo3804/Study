package com.example.testproject.data.entity;

import com.example.testproject.data.dto.ProductDTO;
import lombok.*;
import javax.persistence.*;

@Entity
@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@ToString
@Builder
@Table(name="product")
public class ProductEntity {

    @Id
    String productId;
    String productName;
    Integer productPrice;
    Integer productStock;

}
