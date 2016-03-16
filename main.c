#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stringutils.h>

void test_incrementstring( void );
void test_strstrcnt( void );
void test_substrcntcase( void );
void test_wordcount( void );

int main()
{

#ifdef DEBUG_ON
        puts( "Running tests on the strstrcnt() function." );
#endif
        test_strstrcnt();


#ifdef DEBUG_ON
        puts( "Running tests on the substrcntcase() function." );
#endif
        test_substrcntcase();


#ifdef DEBUG_ON
        puts( "Running tests on the wordcount() function." );
#endif
        test_wordcount();


#ifdef DEBUG_ON
        puts( "Running tests on the incrementstring() function." );
#endif
        test_incrementstring();


        return EXIT_SUCCESS;
}



// A global constant string array, used for testing the functions that
// work with strings.
const char *test_cases[]        = { 
        "The rain in Spain falls mainly on the plain",          "the",
        "Wherever you go, there you are",                       "you",
        "Silence is sometimes the answer",                      "try",
        "Fools and scissors require good handling",             "scissors", 
        "If you have nothing to lose, you can try everything",  "you",
        "Even the best writer has to erase",                    "writer", 
        "Half the truth is often a whole lie",                  "truth",
        "x y z x y z x y z x y z",                              "x",
        "Let your head be more than a funnel to your stomach",  "be", 
        "Strangers are just friends waiting to happen",         "strangers",
        NULL
};



void test_strstrcnt( void )
{
        int test_case_answers[] = { 1, 2, 0, 1, 2, 1, 1, 4, 1, 0 };
        int answer;

        int test_index = 0;
        int count = 0;

#ifdef DEBUG_ON
        puts( "Testing test_strstrcnt():\n" );
#endif

        while ( test_cases[ test_index ] != NULL ) {
                printf( "    %d. testing strstrcnt( %s, %s )... ", 
                        count+1, test_cases[test_index], test_cases[test_index+1] );

                answer = strstrcnt( test_cases[test_index], test_cases[test_index+1] ); 

                if ( answer == test_case_answers[ count ] )
                        printf( "= %d.  Correct!\n", answer );
                else
                        printf( "= INCORRECT: we got \"%d\".  We should be getting \"%d\" instead.\n", 
                                answer, test_case_answers[ count ] );
                count++;
                test_index += 2;
        }
        
        printf( "\n%d tests run.\n\n\n", count );
        return;
}



void test_substrcntcase( void )
{
        int test_case_answers[] = { 2, 2, 0, 1, 2, 1, 1, 4, 1, 1 };
        int answer;

        int test_index = 0;
        int count = 0;

#ifdef DEBUG_ON
        puts( "Testing test_substrcntcase():\n" );
#endif

        while ( test_cases[ test_index ] != NULL ) {
                printf( "    %d. testing substrcntcase( %s, %s )... ", 
                        count+1, test_cases[test_index], test_cases[test_index+1] );

                answer = substrcntcase( test_cases[test_index], test_cases[test_index+1] );     

                if ( answer == test_case_answers[ count ] )
                        printf( "= %d.  Correct!\n", answer );
                else
                        printf( "= INCORRECT: we got \"%d\".  We should be getting \"%d\" instead.\n", 
                                answer, test_case_answers[ count ] );
                count++;
                test_index += 2;
        }
        
        printf( "\n%d tests run.\n\n\n", count );

        return;
}



void test_wordcount( void )
{
        int test_case_answers[] = { 9, 6, 5, 6, 10, 7, 8, 12, 11, 7 };
        int i = 0;
        int answer;

#ifdef DEBUG_ON
        puts( "Testing wordcount():\n" );
#endif

        while ( test_cases[ i ] != NULL ) {
                answer = wordcount( test_cases[i] );
                printf ( "    %d.  %s returned ", i/2+1, test_cases[i] );
                if ( answer == test_case_answers[ i / 2 ] )
                        printf( "%d.  Correct!\n", answer );
                else
                        printf( "%d, which is INCORRECT!  We should get %d.\n", 
				answer, test_case_answers[ i / 2 ] );
                i += 2;
        }
        printf( "\n%d tests run.\n\n\n", i/2 );
        
        return;
}



void test_incrementstring( void )
{
        char *test_cases[]       = { "1", "99",  "a", "d", "z",  "aa", "Az", "zz",  "cw", "tab", "500", NULL };
        char *test_case_answer[] = { "2", "100", "b", "e", "aa", "ab", "Ba", "aaa", "cx", "tac", "501" };
        char *answer;

        int i = 0;

#ifdef DEBUG_ON
        puts( "Testing incrementstring():\n" );
#endif

        while ( test_cases[i] != NULL ) {
                char buffer[10];
        
                strcpy( buffer, test_cases[i] );

                printf( "    %d. testing \"%s\"... ", i+1, buffer );
                answer = incrementstring( buffer );
                if ( strcmp( answer, test_case_answer[i] ) == 0 ) 
                        printf( "= %s.  Correct!\n", answer );
                else
                        printf( "= INCORRECT: we got \"%s\".  We should be getting \"%s\" instead.\n", 
                                answer, test_case_answer[i] );

                i++;
        }
        printf( "\n%d tests run.\n\n\n", i );

        return;
}
