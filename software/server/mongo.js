const MongoClient = require('mongodb').MongoClient;
const assert = require('assert');

const url = 'mongodb://localhost:27017';

const dbName = 'oic';

MongoClient.connect(url, function(err, client) {
  assert.equal(null, err);
  console.log("Connected successfully to server");

  const db = client.db(dbName);


  client.close();
});


const mgFind = function(db, select, callback) {
  const collection = db.collection('documents');
  collection.find(select).toArray(function(err, docs) {
    assert.equal(err, null);
    console.log("Found the following records");
    console.log(docs)
    callback(docs);
  });
}

const mgInsert = function(db, collection, input, callback) {
  const collection = db.collection(collection);
  collection.insertMany(input, function(err, result) {
    assert.equal(err, null);
    console.log("Inserted "+input.length+" documents into the "+collection);
    callback(result);
  });
}

const mgUpdate = function(db, collection, where, set, callback) {
  const collection = db.collection(collection);
  collection.updateOne(where
    , { $set: set}, function(err, result) {
    assert.equal(err, null);
    console.log("Updated the "+collection+" with "+where);
    callback(result);
  });  
}

const mgRemove = function(db, collection, where, callback) {
  const collection = db.collection(collection);
  collection.deleteOne(where, function(err, result) {
    assert.equal(err, null);
    console.log("Removed the "+collection+" with "+where);
    callback(result);
  });    
}
