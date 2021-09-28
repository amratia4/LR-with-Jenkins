Action()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("blazedemo.com", 
		"URL=http://blazedemo.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("TR01_Find Flights button");

	web_add_auto_header("Origin", 
		"https://blazedemo.com");

	web_submit_form("reserve.php", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=fromPort", "Value=Paris", ENDITEM, 
		"Name=toPort", "Value=Buenos Aires", ENDITEM, 
		LAST);

	lr_end_transaction("TR01_Find Flights button",LR_AUTO);

	lr_think_time(16);

	lr_start_transaction("TR02_Click_Choose_This_Flight");

	web_submit_form("purchase.php", 
		"Ordinal=1", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		LAST);

	lr_end_transaction("TR02_Click_Choose_This_Flight",LR_AUTO);

	lr_start_transaction("TR03_Purchase_Flight_Button");

	web_reg_find("Text=Thank you for your purchase today", 
		LAST);

	web_submit_form("confirmation.php", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=inputName", "Value=Amr", ENDITEM, 
		"Name=address", "Value=Test St.", ENDITEM, 
		"Name=city", "Value=Cairo", ENDITEM, 
		"Name=state", "Value=Cairo", ENDITEM, 
		"Name=zipCode", "Value=12345", ENDITEM, 
		"Name=cardType", "Value=Visa", ENDITEM, 
		"Name=creditCardNumber", "Value=", ENDITEM, 
		"Name=creditCardMonth", "Value=11", ENDITEM, 
		"Name=creditCardYear", "Value=2017", ENDITEM, 
		"Name=nameOnCard", "Value=", ENDITEM, 
		"Name=rememberMe", "Value=<OFF>", ENDITEM, 
		LAST);

	lr_end_transaction("TR03_Purchase_Flight_Button",LR_AUTO);

	lr_start_transaction("TR04_Text_Check");

	lr_end_transaction("TR04_Text_Check",LR_AUTO);

	return 0;
}