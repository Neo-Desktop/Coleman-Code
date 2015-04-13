#!/usr/bin/env perl

#constrints.pl

print "Content-Type: text/html; charset=UTF-8\n\n";

uploads_directory => "../uploads/",

meta_redirect => "<meta http-equiv=\"refresh\" content=\"5; url=cgi-bin/$0?view\">",

head => << "__page",
<!DOCTYPE html>
<html>
	<head>
		<title>Project 3 - Amrit Panesar - 77260</title>
		<base href="../">
		<link rel="stylesheet" href="css/jquery-ui.css">
		<link rel="stylesheet" href="css/bootstrap.min.css">
		<link rel="stylesheet" href="css/app.css">
	</head>
	<body>
	<div class="navbar navbar-default navbar-fixed-top">
		<div class="container">
			<div class="navbar-header">
				<a href="./" class="navbar-brand">Project 3</a>
				<button class="navbar-toggle" type="button" data-toggle="collapse" data-target="#navbar-main">
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
				</button>
			</div>
	        <div class="navbar-collapse collapse" id="navbar-main">
        	<ul class="nav navbar-nav">
				<li>
					<a href="cgi-bin/$0?form">Enter Data</a>
				</li>
				<li>
					<a href="cgi-bin/$0?view">View Data</a>
				</li>
				<li>
					<a href="cgi-bin/$0?env">Enviroment</a>
				</li>
			</ul>
		</div>
		</div>
	</div>
	<div class="container">
		<div class="row">
			<div class="col-lg-12">
__page


form => << "__page",
        <form class="form-horizontal" action="cgi-bin/$0?form" method="post" enctype="multipart/form-data">
            <fieldset>
            <legend>Welcome! Please enter your information</legend>
                <div class="form-group">
                    <label for="fn" class="col-lg-2 control-label">First Name</label>
					<div class="col-lg-10">
						<input name="firstname" id="firstname" type="text" placeholder="First Name">
					</div>
                </div>
                <div class="form-group">
                    <label for="ln" class="col-lg-2 control-label">Last Name</label>
					<div class="col-lg-10">
						<input name="lastname" id="lastname" type="text" placeholder="Last Name">
					</div>
                </div>
                <div class="form-group">
                    <label for="addr1" class="col-lg-2 control-label">Address 1</label>
					<div class="col-lg-10">
						<input name="address1" id="addr1" type="text" placeholder="Line 1">
					</div>
                </div>
                <div class="form-group">
                    <label for="address2" class="col-lg-2 control-label">Address 2</label>
					<div class="col-lg-10">
						<input name="address2" id="address2" type="text" placeholder="Line 2">
					</div>
                </div>
                <div class="form-group">
                    <label for="city" class="col-lg-2 control-label">City</label>
					<div class="col-lg-10">
						<input name="city" id="city" type="text" placeholder="City">
					</div>
                </div>
                <div class="form-group">
                    <label for="state" class="col-lg-2 control-label">State</label>
					<div class="col-lg-10">
						<select name="state" id="state"></select>
					</div>
                </div>
                <div class="form-group">
                    <label for="email" class="col-lg-2 control-label">Email</label>
					<div class="col-lg-10">
						<input name="email" id="email" type="email" placeholder="Email">
					</div>
                </div>
                <div class="form-group">
                    <label for="password" class="col-lg-2 control-label">Password</label>
					<div class="col-lg-10">
						<input name="password" id="password" type="password" placeholder="Password">
					</div>
                </div>
                <div class="form-group">
                    <label class="col-lg-2 control-label">Favorite Color</label>
					<div class="col-lg-10">
						<div class="radio">
							<label>
								<input id="o1" type="radio" name="colors" value="Red">
								Red
							</label>
						</div>
						<div class="radio">
							<label>
								<input id="o2" type="radio" name="colors" value="Orange">
								Orange
							</label>
						</div>
						<div class="radio">
							<label>
								<input id="o3" type="radio" name="colors" value="Yellow">
								Yellow
							</label>
						</div>
						<div class="radio">
							<label>
								<input id="o4" type="radio" name="colors" value="Green">
								Green
							</label>
						</div>
					</div>
                </div>
            	<div class="form-group">
					<label class="col-lg-2 control-label">Favorite Sports</label>
					<div class="col-lg-10">
						<div class="checkbox">
							<label>
								<input id="option-one" type="checkbox" name="favoritesport" value="Football">
								Football
							</label>
						</div>
						<div class="checkbox">
							<label>
								<input id="option-two" type="checkbox" name="favoritesport" value="Baseball">
								Baseball
							</label>
						</div>
						<div class="checkbox">
							<label>
								<input id="option-three" type="checkbox" name="favoritesport" value="Basketball">
								Basketball
							</label>
						</div>
						<div class="checkbox">
							<label>
								<input id="option-four" type="checkbox" name="favoritesport" value="Bowling">
								Bowling
							</label>
						</div>
						<div class="checkbox">
							<label>
								<input id="option-five" type="checkbox" name="favoritesport" value="Golf">
								Golf
							</label>
						</div>
					</div>
                </div>

				<div class="clear">&nbsp;</div>
				
                <div class="form-group">
					<label for="citiesToVisit" class="col-lg-2 control-label">Cities To Visit</label>
					<div class="col-lg-10">
						<select name="citiesToVisit" id="citiesToVisit">
						</select>
					</div>
                </div>

                <div class="clear">&nbsp;</div>
				
				<div class="form-group">
					<label for="fileupload" class="col-lg-2 control-label">Upload</label>
					<div class="col-lg-10">
						<button class="btn btn-default btn-file">
							<input id="fileupload" name="file" type="file"/> Browse...
						</button>
						<label id="filename"></label>
					</div>
				</div>

                <div class="clear">&nbsp;</div>
				
                <div class="form-group center">
					<label class="col-lg-2 control-label">&nbsp</label>
					<div class="col-lg-10">
						<button type="submit" class="btn btn-primary">Submit</button>
						&nbsp;
						<button type="reset" class="btn btn-default">Clear</button>
					</div>
                </div>
            </fieldset>
        </form>
__page

table_header => <<"__thead",
	<table class="table table-striped table-hover">
		<thead>
			<tr>
				<th>ID</th>
				<th>First Name</th>
				<th>Last Name</th>
				<th>Address</th>
				<th>Email</th>
				<th>PW Hash</th>
				<th>Color</th>
				<th>Sports</th>
				<th>Visit</th>
				<th>Filename</th>
				<th>Embedded</th>			
			</tr>
		</thead>
		<tbody>
__thead

table_footer => <<"__tfoot",
		</tbody>
	</table>
__tfoot


foot => <<"__page",
			</div>
		</div>
	</div>
	<script src="js/jquery.min.js"></script>
	<script src="js/jquery-ui.min.js"></script>
	<script src="js/bootstrap.min.js"></script>
	<script src="js/app.js"></script>
	</body>
</html>
__page


sql_insert => <<"__SQL",
INSERT INTO `ad77260`.`com330_data`
(	`firstName`, `lastName`, `Address1`,
	`Address2`, `City`, `State`,
	`E-Mail`, `Password`, `Color`,
	`Sports`, `Cities`, `uploadfile`,
	`renamedfile`)
VALUES (?, ?, ?,
		?, ?, ?,
		?, PASSWORD(?), ?,
		?, ?, ?,
		?);
__SQL

sql_select => <<"__SQL",
SELECT `id`, `firstName`, `lastName`,
	CONCAT(`Address1`, "\\n", `Address2`, "\\n", `City`, ", ", `State`) as Address,
	`E-Mail`, `Password`, `Color`,
	`Sports`, `Cities`, `uploadfile`,
	`renamedfile`
FROM `com330_data`
__SQL

default_message => <<"__page",
<h1>Welcome!<h1>
<h2>Please use the above navigation to insert and view data</h2>
<h3>-Amrit</h3>
<h4>Student 77260</h4>
__page
