
#xinput yinput
xi, yi = 0.0,0.0

#converted x/y
cx1, cx2, cy1, cy2 = 0.0,0.0,0.0,0.0

#xoutput youtput
xo, yo = 0.0,0.0

#multipliers
spin = 0.0
diag = 0.0

running = True

while running == True:

    ###get joystick values
    yi = float(input("d_axis_y: "))
    xi = float(input("d_axis_x: "))

    si = float(input("spin_axis: "))
    ###

    ###xdrive conversions
    cy1 = yi; cy2 = yi;
    cx1 = xi; cx2 = -xi;
    ###

    ###drive outputs
    yo = (cy1 + cx1) / 2;
    xo = (cy2 + cx2) / 2;
    ###

    ###diag/smooth multiplier
    diag = abs(abs(yi) - abs(xi)) + 100;

    xo = (xo * diag)/100;
    yo = (yo * diag)/100;

    xo /= 2
    yo /= 2
    ##

    ###spin multiplier
    #spin = (100 - abs(Controller.Axis1.position()));
    ###

    ###apply drive motor control
    print("FL:", (yo - si/2))
    print("BR:", (yo + si/2))
    print("FR:", (xo + si/2))
    print("BL:", (xo - si/2))
    ###