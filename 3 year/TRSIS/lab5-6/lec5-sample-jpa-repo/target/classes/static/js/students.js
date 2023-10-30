var app = angular.module('students', []).config(function ($httpProvider) {
    csrftoken = jQuery("meta[name='_csrf']").attr("content");
    csrfheader = jQuery("meta[name='_csrf_header']").attr("content");
    $httpProvider.defaults.headers.common["X-CSRF-TOKEN"] = csrftoken;
    jQuery(document).ajaxSend(function(e, xhr, options) {
        xhr.setRequestHeader(csrfheader, csrftoken);
    });
});

app.controller("StudentsController", function ($scope, $http) {

    $scope.getStudents = function () {
    $http.get('/public/rest/students')
        .then(function (response) {
            // Обработка успешного запроса
            $scope.studentsList = response.data;
            for (var i = 0; i < $scope.studentsList.length; i++) {
                $scope.studentsList[i].edit = 0;
            }
        })
        .catch(function (error) {
            // Обработка ошибки
            if (error.data && error.data.message === 'Time is out') {
                $scope.finishByTimeout();
            }
        });
};


    $scope.delete = function (id) {
    $http.delete('/public/rest/students/' + id)
        .then(function (response) {
            // Обработка успешного удаления
            for (var i = 0; i < $scope.studentsList.length; i++) {
                var j = $scope.studentsList[i];
                if (j.id === id) {
                    $scope.studentsList.splice(i, 1);
                    break;
                }
            }
        })
        .catch(function (error) {
            // Обработка ошибки
            console.error(error);
        });
};


    $scope.addStudent = function () {
    $http.post('/public/rest/students/' + $scope.fullName + "/" + $scope.assignmentVariant + "/" + $scope.labCount + "/" + $scope.rating + "/" + $scope.groupNumber)
        .then(function (response) {
            // Обработка успешного запроса
            $scope.studentsList.splice(0, 0, response.data);
        })
        .catch(function (error) {
            // Обработка ошибки
            console.error(error);
        });
};

    $scope.searchResults = []; 

$scope.searchStudents = function () {
    $http.get('/public/rest/students/search/' + $scope.searchFullName)
        .then(function (response) {
            $scope.searchResults = response.data;
        })
        .catch(function (error) {
            console.error(error);
        });
};

});
