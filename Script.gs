function doGet(e) {
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  
  // Obtenemos los datos de la URL que mandará la ESP32
  var temp = e.parameter.temp;
  var hum = e.parameter.hum;
  var luz = e.parameter.luz;
  
  // Escribimos los datos en la fila 2 (debajo de tus encabezados)
  // Columna A: Temperatura, B: Humedad, C: Luz
  sheet.getRange("A2").setValue(temp);
  sheet.getRange("B2").setValue(hum);
  sheet.getRange("C2").setValue(luz);
  
  // También podemos poner la fecha y hora en la D2 si querés
  sheet.getRange("D2").setValue(new Date());

  return ContentService.createTextOutput("Datos recibidos correctamente");
}
