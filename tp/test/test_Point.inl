#ifndef TEST_POINT_INCLUDED
#define TEST_POINT_INCLUDED

 #include <polaire.hpp>
 #include <cartesien.hpp>

TEST ( TestPoint, CreatePolaire ) {
   const float r = 12.0;
   const float theta = 24.0;

   Polaire polaire(r,theta);
 
   EXPECT_EQ( polaire.getDistance(), r );
   EXPECT_EQ( polaire.getAngle(), theta ); 
}

TEST ( TestPoint, CreateCartesien ) {
   const float x = 12.0;
   const float y = 24.0;

   Cartesien cartesien(x, y);

   EXPECT_EQ( cartesien.getX(), x );
   EXPECT_EQ( cartesien.getY(), y ); 
}

TEST ( TestPoint, CartesienToPolaireConversion ) {
   const float x = 12.0;
   const float y = 24.0;
   const float expectedR = 26.832815;
   const float expectedT = 1.1071488;

   Cartesien cartesien(x, y);
   Polaire convertedCartesien;
   convertedCartesien.convertir(cartesien);

   EXPECT_EQ( expectedR, convertedCartesien.getDistance() );
   EXPECT_EQ( expectedT, convertedCartesien.getAngle() ); 

}

TEST ( TestPoint, PolaireToCartesienConversion ) {
   const float r = 42.0;
   const float theta = 0.5;
   const float expectedX = 36.858467;
   const float expectedY = 20.135872;

   Polaire polaire(r, theta);
   Cartesien convertedPolaire;
   convertedPolaire.convertir(polaire);

   EXPECT_EQ( expectedX, convertedPolaire.getX() );
   EXPECT_EQ( expectedY, convertedPolaire.getY() );   
}

#endif // TEST_POINT_INCLUDED
