// This file includes some utilities for the input form

$(document).on('change', '.btn-file :file', function() {
    var input = $(this),
        numFiles = input.get(0).files ? input.get(0).files.length : 1,
        label = input.val().replace(/\\/g, '/').replace(/.*\//, '');
    input.trigger('fileselect', [numFiles, label]);
});

$(document).ready( function() {
    $('.btn-file :file').on('fileselect', function(event, numFiles, label) {
        //console.log(numFiles);
        //console.log(label);
		$("#filename").html("Uploading: " + label);
    });
});

// from view-source:http://www.skoolrox.com/COM330/SampleForm.html

$(function() {
	var allStates = { "states" : [
		{ "abbreviation" : "AK", "stateName" : "Alaska" },
		{ "abbreviation" : "AL", "stateName" : "Alabama" },
		{ "abbreviation" : "AR", "stateName" : "Arkansas" },
		{ "abbreviation" : "AZ", "stateName" : "Arizona" },
		{ "abbreviation" : "CA", "stateName" : "California" }
	]};

	var listItem = $('#state');
	$(allStates.states).each(function(index, value) {
		$(listItem).append('<option value="' + value.abbreviation + '">' + value.stateName + '</option>');
	});

	var numbers = ["London", "Tokyo", "New York", "Honolulu", "Sydney", "Paris",
				   "Rome", "Barcelona", "Copenhagen"];
	var option = '';
	for (var i = 0; i < numbers.length; i++){
		option += '<option value="'+ numbers[i] + '">' + numbers[i] + '</option>';
	}
	$('#citiesToVisit').append(option);
	$('#citiesToVisit').attr({
		'multiple': 'multiple',
		'width': '200px',
		'height': '100px'
	});
});