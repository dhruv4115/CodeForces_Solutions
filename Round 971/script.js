// Function to retrieve Slack token securely
function getSlackToken() {
    return PropertiesService.getScriptProperties().getProperty('SLACK_OAUTH_TOKEN');
  }
  
  // Function to send a message to a Slack user by their user IDz
  function sendSlackDM(userId, message) {
    var slackToken = getSlackToken();
    var url = "https://slack.com/api/chat.postMessage";
    
    // Check if userId is valid before proceeding
    if (!userId) {
      console.error("sendSlackDM: userId is null or invalid");
      return;
    }
    
    var payload = {
      "channel": userId,
      "text": message
    };
    
    var options = {
      "method": "post",
      "contentType": "application/json",
      "headers": {
        "Authorization": "Bearer " + slackToken
      },
      "payload": JSON.stringify(payload)
    };
    
    try {
      var response = UrlFetchApp.fetch(url, options);
      var result = JSON.parse(response.getContentText());
      if (!result.ok) {
        console.error("Failed to send Slack message: " + result.error + ". userId: " + userId);
      }
    } catch (e) {
      console.error("Error sending Slack DM: " + e.message);
    }
  }
  
  function getSlackUserId(email) {
    var slackToken = getSlackToken();
    var url = "https://slack.com/api/users.lookupByEmail";
    
    var options = {
      "method": "get",
      "headers": {
        "Authorization": "Bearer " + slackToken
      }
    };
    
    try {
      var response = UrlFetchApp.fetch(url + "?email=" + encodeURIComponent(email), options);
      var result = JSON.parse(response.getContentText());
      
      if (result.ok) {
        console.log("Found user ID for email " + email + ": " + result.user.id);
        return result.user.id;
      } else {
        console.warn("Failed to find user for email " + email + ": " + result.error);
        console.log("Full API response for debugging: " + JSON.stringify(result));
        return null;
      }
    } catch (e) {
      console.error("Error fetching Slack user ID for " + email + ": " + e.message);
      return null;
    }
  }
  
  
  
  
  // Function to check if a user has made an entry today and send reminders
  function checkUserEntryForToday() {
    var sheet = SpreadsheetApp.getActiveSpreadsheet().getSheetByName('DailyUpdates');  
    var lastRow = sheet.getLastRow();
    
    var activeSheet = SpreadsheetApp.getActiveSpreadsheet().getSheetByName('ActiveUsers');  
    var activeInterns = activeSheet.getRange(1, 2, activeSheet.getLastRow(), 1).getValues().flat();
    
    var today = new Date();
    today.setHours(0, 0, 0, 0);
  
    // Loop through entries in the "Daily Updates" sheet
    for (var i = lastRow - 8; i <= lastRow; i++) {  
      var timestamp = sheet.getRange(i, 1).getValue();
      var email = sheet.getRange(i, 2).getValue();  
      var status = sheet.getRange(i, 3).getValue();  
  
      if (activeInterns.includes(email)) {
        if (!timestamp || new Date(timestamp).setHours(0, 0, 0, 0) !== today.getTime()) {
          var userId = getSlackUserId(email);  
          if (userId) {
            var message = `Hello, please remember to fill in your login/logout status for today.`;
            sendSlackDM(userId, message);  
          }
        }
      }
    }
  }
  