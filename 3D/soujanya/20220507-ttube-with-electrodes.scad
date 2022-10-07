linear_extrude(height = 45){
    difference() {
        union() {
            translate([-6,-6])
            square([12,12]);
        }    
        union() {
            translate([-5,-4])
            square([10,8]);
            translate([-1.5,-5])
            square([3,10]);
            translate([-5.0,-5])
            square([3.1,10]);
            translate([1.9,-5])
            square([3.1,10]);
        }
    }
}

linear_extrude(height = 2)
translate([-6,-6])
square([12,12]);