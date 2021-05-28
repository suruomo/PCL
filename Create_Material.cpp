


















































































































































































































































CLASS Create_Material
	
CLASSWIDE WIDGET form_id,@
type_menu,select_button,cancel_button


FUNCTION init()
real x_loc,y_loc
	
x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )
	
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 1 ),uil_form_sizes.form_y_loc( 1 ), "UL",uil_form_sizes.form_wid( 1 ),uil_form_sizes.form_hgt( 3 ), "Create Material", "" )


	
type_menu=ui_optionmenu_create(form_id,"",x_loc,y_loc,0.0,"Material Type:",FALSE)
ui_item_create(type_menu,"Isotropic","Isotropic",FALSE)
ui_item_create(type_menu,"2D_Orthotropic","2D Orthotropic",FALSE)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )

	
select_button=ui_button_create(form_id, "select_material_db", uil_form_sizes.button_x_loc1( 1 ), y_loc, uil_form_sizes.button_wid( 1 ), 0.,"Select Material From Database", TRUE, FALSE)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


cancel_button=ui_button_create(form_id, "cancel", uil_form_sizes.button_x_loc1( 1 ), y_loc, uil_form_sizes.button_wid( 1 ), 0.,"Cancel", FALSE, FALSE)


END FUNCTION


FUNCTION display()
	ui_form_display("Create_Material")
END FUNCTION




FUNCTION select_material_db()
ui_write("Select Material From Database.....")
STRING item [20]
ui_wid_get (type_menu,"VALUE", item)
	IF(item=="Isotropic")THEN
			 ui_exec_function("Mat1","init")
Mat1.display()
ELSE
ui_exec_function("Mat8","init")
Mat8.display()
END IF


END FUNCTION




FUNCTION cancel()
ui_form_hide("Create_Material")
END FUNCTION


END CLASS
