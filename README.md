# corrector-ortografico
Un corrector ortográfico basado en la estructura de datos Trie, implementado en C++ (Estructuras de Datos, Primer Semestre 2016).

### Descripción del Problema
En este proyecto se pide implementar un corrector ortográfico simple para el español o inglés. El corrector ortográfico incorporará una base de datos de palabras, y será construido a partir de una lista de palabras, organizando la información de tal forma que se pueda hacer una búsqueda eficiente.

Las palabras a ser corregidas se leen, una por una, de un archivo de entrada (de texto) y son entregadas al corrector ortográfico para su procesamiento. Si el corrector ortogr ́afico encuentra una coincidencia exacta, éste simplemente indica que la palabra está escrita correctamente. Si no es así, el corrector ortográfico retornará una lista (posiblemente vacía) de sugerencias ortográficas. Para seleccionar las sugerencias, el corrector ortográfico aplica reglas para decidir si una palabra es candidata a ser la forma correcta de escribir la palabra. Supongamos que _M_ es la palabra cuya ortografía se está comprobando, y que una palabra _C_ es candidata a la lista de palabras sugeridas. El corrector ortográfico considerará que _C_ es una sugerencia para _M_ aplicando las siguientes reglas (en el orden dado):

* Si las longitudes de _M_ y _C_ difieren en m ́as de dos, entonces _C_ no se sugiere.

* Si _M_ es un prefijo de _C_, o si _C_ es un prefijo de _M_ , entonces se sugiere _C_.

* Comparar, uno a uno desde el comienzo, los caracteres de _M_ y _C_ hasta terminar uno o ambos strings
(lo que ocurra primero). Si hay a lo m ́as dos diferencias, y ambos _M_ y _C_ son de largo mayor a tres, entonces sugiera _C_.

Estas reglas son un tanto arbitrarias y demasiado simples para un corrector ortogr ́afico real. Sin embargo son
aceptables para esta tarea donde el objetivo principal es el diseño de la estructura de datos y no el algoritmo de comparación. Reglas más sofisticadas podrán ser bonificadas con crédito extra.

### Implementación
El programa debe ser llamado por línea de comandos recibiendo como par ́ametros: el archivo que contiene las palabras del diccionario, el archivo con el texto a revisar y un log con las correcciones. Una llamada al
programa debe ser de la forma:
> corrector archivo\_diccionario archivo\_a\_revisar log\_revision

El programa debe verificar la existencia de los dos primeros archivos de entrada e imprimir un error si alguno no existe. El contenido y formato de los archivo de entrada *archivo_diccionario* *archivo_a_revisar* y
salida *log_revision* se encuentra detallado más abajo.

Existen diversas formas de implementar un corrector ortográfico. En este proyecto la implementación debe ajustarse a las siguientes restricciones:
* El diccionario de palabras debe almacenarse en un árbol especial denominado trie (ver Anexo A). Esta sencilla pero potente estructura de datos no se suele ver en el curso básico de Estructuras de Datos pero, dada su simplicidad y semejanza con cualquier otra implementación de  ́arboles, la descripciócluida en el anexo debería ser suficiente para su implementación.

* El corrector ortográfico debe ser implementado como una clase. Contendrá un trie, pero no será simplemente un trie.
* Debe existir una clase "controladora" que se preocupe de procesar los archivos de entrada y de crear el archivo de salida. Esta clase contendrá un corrector ortográfico (y probablemente otras variables más).

* En la implementación se deben respetar los principios de buen diseño, abstracci ́on y encapsulamiento. Por ejemplo, debe definir una interfaz para el corrector ortográfico, el  ́arbol no debe asumir responsabilidades que no le pertenezcan como la lectura de palabras a revisar o la construcción de la lista de sugerencias de palabras alternativas, la representación debe ser privada y las modificaciones y consultas se deben hacer sólo a través de métodos.

### Archivos
Los archivos de entrada y salida del programa son los siguientes:  
1. **archivo_diccionario:** archivo de entrada que contiene una palabra por línea. Puede contener comentarios partiendo con el símbolo %. Pueden encontrar ejemplos de diccionarios [aquí](http://www.winedt.org/dict.html). Asuma que todas las palabras est ́án con minúsculas

2. **archivo_a_revisar:** archivo que contiene el texto a revisar. El archivo puede contener puntuación y combinaciones de mayúsculas y minúsculas. Para poder hacer comparaciones válidas será necesario procesar el texto de tal forma de extraer cada palabra (delimitada por un espacio al principio y otro al final), luego reemplazar todas las mayúsculas por minúsculas y eliminar cualquier puntuaci ́on que haya al principio o al final. Por ejemplo si encuentra la palabra "*Hola*" revisará la palabra "*hola*". Si encuentra el texto "*Claro!!!*"
revisará "*claro*".

3. **log_revision:** este archivo de salida debe contener el log de la revisión ortográfica del *archivo_a_revisar*. Debe contener:

 * Nombre del alumno, nombre del archivo que se revisó y diccionario utilizado para la revisión (URL en la cuál está disponible para descarga). Cada una de estas cosas debe estar impresa en una línea.

 * Un listado donde cada fila incluya primero la palabra mal escrita y luego la lista de correcciones sugeridas para ella (en orden lexicográfico) desplegadas de la siguiente forma:
 *palabra_mal_escrita:* *lista_de_sugerencias*  
  No se deben desplegar las palabras bien escritas. Es importante mantener este formato para poder automatizar parcialmente la corrección de la tarea.

 * Un resumen de estadísticas de la revisión que incluya: número total de palabras que contiene el diccionario, número de palabras escritas correctamente y número de palabras con error. Cada una en una línea.

### Evaluación
El proyecto se realizará en parejas. Enviar en piazza (mensaje privado a Instructors) lo siguiente:  
1. Un informe que:
 * Incluya portada, descripción de la tarea, descripción de la solución propuesta (puede emplear diagramas de clase para explicar la solución) y detalles de implementación.

 * Sea claro y esté bien escrito. Un informe difícil de entender es un informe que será mal evaluado aunque todo esté bien implementado. La persona que revise el documento debe poder entender su solución sólo mirando el informe.

 * Esté en formato pdf.

2. Un archivo comprimido con todos los ficheros fuente implementados para solucionar la tarea. El informe debe hacer referencia a ellos y explicar en qué consiste cada uno.

**Fecha de Entrega: viernes 13 de Mayo 11:59PM**
