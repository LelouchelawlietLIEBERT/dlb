
import json
import xml.etree.ElementTree as ET

# JSON data
json_data = """
{
    "title": "Data Science Book",
    "author": "Joel Grus",
    "publicationYear": 2019,
    "topics": ["data", "science", "data science"]
}
"""

# XML data
xml_data = """
<book>
    <title>Data Science Book</title>
    <author>Joel Grus</author>
    <publicationYear>2019</publicationYear>
    <topics>
        <topic>data</topic>
        <topic>science</topic>
        <topic>data science</topic>
    </topics>
</book>
"""

# --- JSON Parsing and Validation ---
print("JSON Check:")
data_json = json.loads(json_data)
if data_json["publicationYear"] == 2019:
    print("Success!")
else:
    print("Failed!")
if "data science" in data_json["topics"]:
    print("Success!")
else:
    print("Failed!")

# --- XML Parsing and Validation ---
print("\nXML Check:")
root = ET.fromstring(xml_data)
pub_year_xml = int(root.find("publicationYear").text)
topics_xml = [topic.text for topic in root.find("topics").findall("topic")]

if pub_year_xml == 2019:
    print("Success!")
else:
    print("Failed!")
if "data science" in topics_xml:
    print("Success!")
else:
    print("Failed!")
