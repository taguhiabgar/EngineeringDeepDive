//
//  Classwork4.h
//  CppTemplates
//
//  Created by Taguhi Abgar on 15.03.25.
//

#ifndef Classwork4_h
#define Classwork4_h

void print()
{
    
}

/// This function prints to console all the provided arguments.
template< typename HeadType, typename... Types >
void print( const HeadType& head, Types... body )
{
    print( body... );
    std::cout << " " << head;
}

void Classwork4_DriverProgram() {
    // Part 1.1
    
    print( 12, "ABC", 9.8 );
    std::cout << std::endl;
    print( 8.2, 'x', 'y', "variance" );
    


//    // Part 2
//    {
//        std::cout << "Sequence 1:";
//        print_integers< 8, 12, 9 >();
//
//        std::cout << "Sequence 2:";
//        print_integers< 7, 61, 4, 27 >();
//    }
    
}

#endif /* Classwork4_h */
