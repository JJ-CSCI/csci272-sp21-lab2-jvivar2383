//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};

// Write your code here
class GPS {

  double latitude;
  Compass latitudeDirection;
  double longitude;
  Compass longitudeDirection;

  public:

  double getLatitude(){
    return latitude;
  };

  double getLongitude(){
    return longitude;
  };

  Compass getLatitudeDirection(){
    return latitudeDirection;
  };

  Compass getLongitudeDirection(){
    return longitudeDirection;
  }

  GPS(double new_latitude, Compass new_latitudeDirection,double new_longitude, Compass new_longitudeDirection){

    latitude = new_latitude;
    longitude = new_longitude;
    latitudeDirection = new_latitudeDirection;
    longitudeDirection = new_longitudeDirection;
    
    if(latitude < 0.0 || latitude > 90.0){
      latitude = 0.0;
      latitudeDirection = Compass::N;
    }
    if(longitude > 180.0 || longitude < 0.0){
      longitude = 0.0;
      longitudeDirection = Compass::W;
    }
    if (longitudeDirection == Compass::N || longitudeDirection == Compass::S ){
      longitudeDirection = Compass::W;
    }
    if(latitudeDirection == Compass::W || latitudeDirection == Compass::E){
      latitudeDirection = Compass::N;
    }
  }
  GPS(double new_latitude, double new_longitude){
    latitudeDirection = Compass::N;
    longitudeDirection = Compass::W;
    latitude = new_latitude;
    longitude = new_longitude;

    if(latitude < 0.0 || latitude > 90.0){
      latitude = 0.0;
      latitudeDirection = Compass::N;
    }
    if(longitude > 180.0 || longitude < 0.0){
      longitude = 0.0;
      longitudeDirection = Compass::W;
    }
    
  }

  GPS(){
    latitude = 0.0;
    longitude = 0.0;
    latitudeDirection = Compass::N;
    longitudeDirection = Compass::W;
  }


  

};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------
