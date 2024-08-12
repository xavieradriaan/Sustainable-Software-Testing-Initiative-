#include <WiFi.h>
#include <WebServer.h>

// Configuración de la red Wi-Fi
const char* ssid = "G.Network";
const char* password = "0Ab15444088";

// Crear una instancia del servidor web en el puerto 80
WebServer server(80);

// Página HTML que se servirá
const char* html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>Sustainable Software Testing Initiative</title>
    <style>
        body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; margin: 0; padding: 0; background-color: #f4f4f9; }
        .header { background-color: #2E8B57; color: white; padding: 20px; text-align: center; }
        .container { max-width: 800px; margin: 40px auto; padding: 20px; background: #fff; border-radius: 10px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); }
        h1 { color: #2E8B57; text-align: center; }
        p { font-size: 18px; color: #333; }
        ul { list-style-type: none; padding: 0; }
        li { background: #e0f7fa; margin: 10px 0; padding: 10px; border-radius: 5px; }
        .footer { background-color: #2E8B57; color: white; text-align: center; padding: 10px; position: fixed; width: 100%; bottom: 0; }
        .button { display: inline-block; padding: 10px 20px; font-size: 16px; color: white; background-color: #2E8B57; border: none; border-radius: 5px; text-align: center; cursor: pointer; }
        .button:hover { background-color: #3CB371; }
    </style>
</head>
<body>
    <div class="header">
        <h1>Sustainable Software Testing Initiative</h1>
    </div>
    <div class="container">
        <p>Leading a project to integrate sustainability practices into software testing, including:</p>
        <ul>
            <li>Energy-efficient test execution</li>
            <li>Carbon footprint reduction</li>
            <li>Eco-friendly practices</li>
        </ul>
        <button class="button" onclick="alert('Sustainability is the future!')">Learn More</button>
    </div>
    <div class="footer">
        <p>&copy; 2023 Sustainable Software Testing Initiative</p>
    </div>
</body>
</html>
)rawliteral";

// Función para manejar la solicitud raíz
void handleRoot() {
  server.send(200, "text/html", html);
}

void setup() {
  // Iniciar la comunicación serial
  Serial.begin(115200);

  // Conectar a la red Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected to WiFi. IP address: ");
  Serial.println(WiFi.localIP());

  // Configurar el manejador de la solicitud raíz
  server.on("/", handleRoot);

  // Iniciar el servidor
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Manejar las solicitudes del cliente
  server.handleClient();
}