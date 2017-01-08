#include "simple_factory.h"

int main(void) {
  auto factory = std::static_pointer_cast<Factory>(
      std::make_shared<ConcreteFactory>());

  auto product = factory->GetProduct(PRODUCT1); //factory generate an product
  product->TellProductName(); // use product to do some thing

  // factory generate another product
  product = factory->GetProduct(PRODUCT2);  
  product->TellProductName();
  return 0;
}
