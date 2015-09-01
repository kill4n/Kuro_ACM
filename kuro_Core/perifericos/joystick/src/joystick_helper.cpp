#include "joystick_helper.h"

joystick_helper::joystick_helper():num_of_axis(0),
    num_of_buttons(0)
{
}

int joystick_helper::openJoy()
{
    if( ( joy_fd = open( JOY_DEV , O_RDONLY)) == -1 )
    {
        printf( "No se pudo abrir Joystick\n" );
        return -1;
    }
    else {
        printf("Se pudo conectar el Joystick\n");
        ioctl( joy_fd, JSIOCGAXES, &num_of_axis );
        ioctl( joy_fd, JSIOCGBUTTONS, &num_of_buttons );
        ioctl( joy_fd, JSIOCGNAME(80), &name_of_joystick );

        axis = (int *) calloc( num_of_axis, sizeof( int ) );
        button = (char *) calloc( num_of_buttons, sizeof( char ) );

        printf("Joystick detectado: %s\n\t%d ejes\n\t%d botones\n\n"
               , name_of_joystick
               , num_of_axis
               , num_of_buttons );

        fcntl( joy_fd, F_SETFL, O_NONBLOCK );	/* use non-blocking mode */
    }
}

int joystick_helper::closeJoy()
{
    close( joy_fd );	/* Cerrar el Joystick */
}
