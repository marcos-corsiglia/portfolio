<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Contacto</title>
</head>
<body>
       
<?php

    $nombre = $_POST['nombre'];
    $email = $_POST['mail'];
    $pregunta = $_POST['pregunta'];

    $header = 'From: ' . $email . '\r\n';
    $header .= 'X-Mailer: PHP/' . phpversion() . '\r\n';
    $header .= 'Content.Type: text/plain';

    $para = 'grupo04@localhost';
    $asunto = 'Contacto desde la Web';
    $mensaje = 'Nombre:' . $nombre . '\nMail: ' . $email . '\nPregunta: ' . $pregunta;

    mail($para, $asunto, $mensaje, $header);

    header('Location: success_contact.html');
    exit();

?>
</body>
</html>