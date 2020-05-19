#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

class Instructions 
{
    private:
      //  char    *ptr;

    public:
            Instructions(){}
        virtual ~Instructions() {}
        virtual char *execute(char *ptr) = 0;
        virtual char getName() = 0;
};

#endif