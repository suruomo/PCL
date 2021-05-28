


















































































































































































































































CLASS Mat1
	
CLASSWIDE WIDGET form_id,select_button,apply_button,cancel_button


FUNCTION init()


real x_loc,y_loc


GLOBAL WIDGET Material_Name,Elastic_Modulus,Possion_Ratio,Shear_Modulus,Density,Thermal_Expan_Coeff,Structural_Damping_Coeff,Reference_Temperature


x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )
	
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 1 ),uil_form_sizes.form_y_loc( 1 ), "UL",uil_form_sizes.form_wid( 1 ),uil_form_sizes.form_hgt( 3 ), "Isotropic Material", "" )


	
Material_Name=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Material Name:","",TRUE,"STRING",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Elastic_Modulus=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Elastic Modulus:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Possion_Ratio=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Possion Ratio:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Shear_Modulus=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Shear Modulus:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Density=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Density:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Thermal_Expan_Coeff=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Thermal Expan.Coeff:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Structural_Damping_Coeff=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Structural Damping Coeff:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Reference_Temperature=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Reference Temperature:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )

	
select_button=ui_button_create(form_id, "select_mat1_material", uil_form_sizes.button_x_loc1( 1 ), y_loc, uil_form_sizes.button_wid( 1 ), 0.,"Select Material From Database", TRUE, FALSE)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


apply_button=ui_button_create(form_id, "apply", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Apply", FALSE, FALSE)


cancel_button=ui_button_create(form_id, "cancel", uil_form_sizes.button_x_loc1( 3 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Cancel", FALSE, FALSE)


END FUNCTION


FUNCTION display()


	ui_form_display("Mat1")
END FUNCTION




FUNCTION select_mat1_material()
ui_write("Select Isotropic Material From Database.....")
ui_exec_function("Mat1_List","init")
Mat1_List.display()
END FUNCTION


FUNCTION apply()
REAL EM,PR,SM,D,TEC,SDC,RT
STRING name[200]
STRING result[64](8)
GLOBAL WIDGET Material_Name,Elastic_Modulus,Possion_Ratio,Shear_Modulus,Density,Thermal_Expan_Coeff,Structural_Damping_Coeff,Reference_Temperature
ui_wid_get(Material_Name,"VALUE",name)
ui_wid_get(Elastic_Modulus,"VALUE",EM)
ui_wid_get(Possion_Ratio,"VALUE",PR)
ui_wid_get(Shear_Modulus,"VALUE",SM)
ui_wid_get(Density,"VALUE",D)
ui_wid_get(Thermal_Expan_Coeff,"VALUE",TEC)
ui_wid_get(Structural_Damping_Coeff,"VALUE",SDC)
ui_wid_get(Reference_Temperature,"VALUE",RT)


result(1)=str_from_real(EM)
result(2)=str_from_real(PR)
result(3)=str_from_real(SM)
result(4)=str_from_real(D)
result(5)=str_from_real(TEC)
result(6)=str_from_real(SDC)
result(7)=str_from_real(RT)
result(8)=""




material.create( "Analysis code ID", 1, "Analysis type ID", 1, name, 0, @
"Date: 27-Nov-12 Time: 04:59:56", "Isotropic", 1, "Directionality", @
1, "Linearity", 1, "Homogeneous", 0, "Linear Elastic", 1, @
"Model Options & IDs", ["", "", "", "", ""], [0, 0, 0, 0, 0], "Active Flag", @
1, "Create", 10, "External Flag", FALSE, "Property IDs", ["Elastic Modulus", @
"Poisson Ratio", "Shear Modulus", "Density", "Thermal Expan. Coeff", @
"Structural Damping Coeff", "Reference Temperature"], [2, 5, 8, 16, 24, 30, @
1,0], "Property Values",result )


ui_write("Create Material Successful")
END FUNCTION


FUNCTION cancel()
ui_form_hide("Mat1")
END FUNCTION


END CLASS
