# ConsoleTools
Helpful utilities for pleasant development

- ConsoleColorer Usage:
 
        cout << Colored(Red) << "Red Warning Text! " << Colored(Yellow) << "Lemons!";
        cout << "This text is normal again!";
        cout << Colored(BackgroundColor(Gray) | FontColor(Blue)) << "This is blue text on gray background!";
