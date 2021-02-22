# Lab 2

## Task: GPS Coordinates

Write a class for storing a GPS coordinate, [latitude](https://en.wikipedia.org/wiki/Latitude) and [longitude](https://en.wikipedia.org/wiki/Longitude). Longitude lines are perpendicular to and latitude lines are parallel to the [Equator](https://en.wikipedia.org/wiki/Equator). The latitude of a point on Earth's surface is the angle between the equatorial plane and the straight line that passes through that point and through (or close to) the center of the Earth. The longitude of a point on Earth's surface is the angle east or west of a reference meridian to another meridian that passes through that point.

<a title="Unknown author, Public domain, via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:FedStats_Lat_long.svg"><img width="400" alt="FedStats Lat long" src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/ef/FedStats_Lat_long.svg/360px-FedStats_Lat_long.svg.png"></a>

### Details

- Define a class `GPS` that will store latitude and longitude coordinates
  - Latitude angle value can only be in range `[0.0, 90.0]`
  - Latitude direction value can only be either `Compass::N` or `Compass::S`
  - Longitude angle value can only be in range `[0.0, 180.0]`
  - Longitude direction value can only be either `Compass::W` or `Compass::E`
- Use the provided [enum class](https://www.learncpp.com/cpp-tutorial/enum-classes/) `Compass` to specify a coordinate direction
- The class must have following data members
  - `latitude` for storing the latitude angle value, `double` type
  - `latitudeDirection` for storing the latitude direction, `Compass` type
  - `longitude` for storing the longitude angle value, `double` type
  - `longitudeDirection` for storing the longitude direction, `Compass` type
  - All data members must have **private** access
- The class must contain following accessor methods that allow read-only access to the encapsulated fields
  - `getLatitude` returns the latitude angle, `double` type
  - `getLatitudeDirection` returns the latitude direction, `Compass` type
  - `getLongitude` returns the longitude angle, `double` type
  - `getLongitudeDirection` returns the longitude direction, `Compass` type
- Define the class constructors that initialize an object of `GPS` class under the following conditions
  - If no coordinates are specified during the object instantiation then the latitude and longitude angles are set to zero, the latitude direction is set to `Compass::N`, and the longitude direction is set to `Compass::W`
  - If only the latitude and longitude angles are specified during the object instantiation, then the latitude direction is `Compass::N`, and the longitude direction is `Compass::W`
  - If the latitude coordinate is initialized with a value that is outside of the designated range then the coordinate is set to `0°N`
  - If the longitude coordinate is initialized with a value that is outside of the designated range then the coordinate is set to `0°W`
- Make sure that your program compiles without errors

## Test

Press **Run** button to execute and test your program.

- Or run `make test` command in the command line to verify the correctness of your program.

## Submission

- Commit & push all changes that to the corresponding assignment repository on GitHub, using the **Repl.it** interface - **Version control** tab.
  - Make sure that you committed changes of the following files:
    - `main.cpp`
- Submit the link of the assignment GitHub repository in the corresponding assignment submission the Blackboard.

### Before You Submit

You are required to test that your submission works properly before submission. Make sure that your program compiles without errors. Once you have verified that the submission is correct, you can submit your work.

### Coding Style

In any programming project, matching the existing coding style is important. Having different coding styles intermixed leads to confusion and bugs. Students are required to follow the particular existing coding style that maintains the indentation style in `.cpp` and `.h` files using spaces, not tabs.

In particular, pay close attention to function declarations and how the function name begins the line after the function return type. For helper functions which are limited in scope to a specific file, you must declare the function as `static` in the same file in which it is used.

*Indentation*: The indentation style for your work have to be 4 spaces. Many students are taught to use tabs for indentation, which can make code very hard to read, especially when there are several levels of indentation.

For additional information of C++ coding style see [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
