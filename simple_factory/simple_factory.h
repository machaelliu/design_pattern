/**********************************************************
 * Author        : qingtao5
 * Email         : qingtao5@staff.weibo.com
 * Create time   : 2017-01-08 20:49
 * Last modified : 2017-01-08 20:49
 * Filename      : simple_factory.h
 * Description   : 
 * *******************************************************/
#ifndef SIMPLE_GRAPHIC_H_
#define SIMPLE_GRAPHIC_H_

#include <iostream>
#include <memory>
typedef enum { PRODUCT1, PRODUCT2 } product_type_t; 

class Product {
 public:
   virtual void TellProductName() = 0; 
};

class ConcreteProduct1:public Product {
 public:
   void TellProductName() {
     std::cout << "ConcreteProduct1" << std::endl;
   }
};

class ConcreteProduct2:public Product {
 public:
   void TellProductName() {
     std::cout << "ConcreteProduct2" << std::endl;
   }
};

// Factory can be concrete, too. It can point different concrete factories 
// when make it abstract
class Factory {
 public:
   virtual std::shared_ptr<Product> GetProduct(product_type_t type) = 0;
};

class ConcreteFactory:public Factory {
 public:
    std::shared_ptr<Product> GetProduct(product_type_t type) {
     std::shared_ptr<Product> product;
     switch (type) {
       case PRODUCT1:
         product = std::static_pointer_cast<Product>(
             std::make_shared<ConcreteProduct1>());
         break;
       case PRODUCT2:
         product = std::static_pointer_cast<Product>(
             std::make_shared<ConcreteProduct2>());
         break;
     }

     return product;
   }
};

#endif
