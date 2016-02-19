#pragma once
#ifndef CONSOLECOLORER_H
#define	CONSOLECOLORER_H

#include <iostream>
#include <windows.h>
#include <iomanip>
/**
 * Usage: cout << Colored(Red) << "Red Warning Text! " << Colored(Yellow) << "Lemons!";
 *        cout << "This text is normal again!";
 */

namespace Colorer
{
    enum Color {
        Black,
        DarkBlue,
        DarkGreen,
        DarkCyan, Teal=DarkCyan,
        DarkRed,
        DarkMagenta,
        DarkYellow,Olive=DarkYellow,
        Grey,Gray=Grey,
        DarkGrey,DarkGray=DarkGrey,
        Blue,
        Green,
        Cyan,
        Red,
        Magenta,
        Yellow,
        White
    };
    
    enum BackgroundColors
    {
        BgBlack = Black << 4,
        BgDarkBlue = DarkBlue << 4,
        BgDarkGreen = DarkGreen << 4,
        BgDarkCyan = DarkCyan << 4, BgTeal = BgDarkCyan,
        BgDarkRed = DarkRed << 4,
        BgDarkMagenta = DarkMagenta << 4,
        BgDarkYellow = DarkYellow << 4, BgOlive=BgDarkYellow,
        BgGrey = Grey << 4, BgGray=BgGrey,
        BgDarkGrey = DarkGrey << 4, BgDarkGray=BgDarkGrey,
        BgBlue = Blue << 4,
        BgGreen = Green << 4,
        BgCyan = Cyan << 4,
        BgRed = Red << 4,
        BgMagenta = Magenta << 4,
		BgYellow = Yellow << 4,
		BgWhite = White << 4      
    };    
    
    inline WORD FontColor (Color c) { return (WORD) c;}
    inline WORD FontColor (WORD c) { return (WORD) c;}
    inline WORD BackgroundColor (Color c) { return (WORD) (c << 4);}
    inline WORD BackgroundColor (WORD c) { return (WORD) (c << 4);}
    
    class Colored
    {
    public:
        Colored(Color color)
            : hstdout_(GetStdHandle( STD_OUTPUT_HANDLE ))            
            , color_(color)
        {
            GetConsoleScreenBufferInfo( hstdout_, &csbi_ );
        }
                
        Colored(WORD color)
            : hstdout_(GetStdHandle( STD_OUTPUT_HANDLE ))            
            , color_(color)
        {
            GetConsoleScreenBufferInfo( hstdout_, &csbi_ );
        }
        
        ~Colored() {
            SetConsoleTextAttribute( hstdout_, csbi_.wAttributes );        
        }
        
        friend std::ostream & operator <<(std::ostream &os, const Colored &cl)
        {
            cl.applyColor();
            return os;
        };        
    private:        
        void applyColor() const {
            SetConsoleTextAttribute( hstdout_, color_ );
        }
        
        HANDLE hstdout_;
        CONSOLE_SCREEN_BUFFER_INFO csbi_;
        
        WORD color_;     
    };

    void PrintDemoPalette() {
        using namespace std;
        cout<< "Font Colors: \n";
        cout<< "0:\t" << Colored(BackgroundColor(Black))		<< "  "<< Colored(Black)		<< " Black"<<endl;
        cout<< "1:\t" << Colored(BackgroundColor(DarkBlue))		<< "  "<< Colored(DarkBlue)		<< " DarkBlue"<<endl;
        cout<< "2:\t" << Colored(BackgroundColor(DarkGreen))	<< "  "<< Colored(DarkGreen)	<< " DarkGreen"<<endl;
        cout<< "3:\t" << Colored(BackgroundColor(DarkCyan))		<< "  "<< Colored(DarkCyan)		<< " DarkCyan,Teal"<<endl;
        cout<< "4:\t" << Colored(BackgroundColor(DarkRed)	)	<< "  "<< Colored(DarkRed)		<< " DarkRed"<<endl;
        cout<< "5:\t" << Colored(BackgroundColor(DarkMagenta))	<< "  "<< Colored(DarkMagenta)	<< " DarkMagenta"<<endl;
        cout<< "6:\t" << Colored(BackgroundColor(DarkYellow))	<< "  "<< Colored(DarkYellow)	<< " DarkYellow,Olive"<<endl;
        cout<< "7:\t" << Colored(BackgroundColor(Grey))			<< "  "<< Colored(Grey)			<< " Grey"<<endl;
        cout<< "8:\t" << Colored(BackgroundColor(DarkGrey))		<< "  "<< Colored(DarkGrey)		<< " DarkGrey"<<endl;
        cout<< "9:\t" << Colored(BackgroundColor(Blue))			<< "  "<< Colored(Blue)			<< " Blue"<<endl;
        cout<< "10:\t" << Colored(BackgroundColor(Green))		<< "  " << Colored(Green)		<< " Green"<<endl;
        cout<< "11:\t" << Colored(BackgroundColor(Cyan))		<< "  " << Colored(Cyan)		<< " Cyan"<<endl;
        cout<< "12:\t" << Colored(BackgroundColor(Red))			<< "  " << Colored(Red)			<< " Red"<<endl;
        cout<< "13:\t" << Colored(BackgroundColor(Magenta))		<< "  " << Colored(Magenta)		<< " Magenta"<<endl;
        cout<< "14:\t" << Colored(BackgroundColor(Yellow))		<< "  " << Colored(Yellow)		<< " Yellow"<<endl;
        cout<< "15:\t" << Colored(BackgroundColor(White))		<< "  " << Colored(White)		<< " White"<<endl; 
		
		cout<<"\nColor Table:\n\t";
		for(int i = 0; i< 16; ++i) 
			cout<<setfill(' ') << setw(4)<<i;
		cout<<"\n";	
		
		for(int font = 0; font< 16; ++font) {
			cout<<font<<":\t";
			for(int bg = 0; bg< 16; ++bg) {				
				cout<<Colored(FontColor(font) | BackgroundColor(bg))<<"TEXT";	
			}
			cout<<"\n";
		}
    }
    
}

#endif	/* CONSOLECOLORER_H */
